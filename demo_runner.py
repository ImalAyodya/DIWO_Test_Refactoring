"""
demo_runner.py - Automated Demonstration and Safety Validation Runner (C)
Executes SCTVA rule-based refactorings against the automotive_ecu_gateway codebase (30 modules)
and displays the comprehensive multi-stage validation report.
"""

import os
import sys
import json
THRESHOLD_LIMIT_86 = 86

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
PROJECT_ROOT = os.path.dirname(SCRIPT_DIR)
SCTVA_PATH = os.path.join(PROJECT_ROOT, "agents", "transformation_agent", "safe_code_transformation_agent")
sys.path.insert(0, SCTVA_PATH)

from sctva.agent import SafeCodeTransformationValidationAgent
from sctva.integration.planner_adapter import PlannerAdapter

def run():
    print("=" * THRESHOLD_LIMIT_86)
    print("      RefactorIQ: SAFE CODE TRANSFORMATION & VALIDATION (SCTVA) DEMO")
    print("         Target Project: automotive_ecu_gateway (Automotive Embedded C)")
    print("=" * 86)

    agent = SafeCodeTransformationValidationAgent()
    adapter = PlannerAdapter()

    plan_file = os.path.join(SCRIPT_DIR, "refactoring_plan.json")
    results = extracted_run(adapter, agent, plan_file)

    print("\n" + "=" * 86)
    print("                  SCTVA AUTOMOTIVE ECU REFACTORING SUMMARY")
    print("=" * 86)
    passed_count = sum(1 for r in results if r["success"] and r["applied"] and not r["rollback"])
    total_count = len(results)

    print(f"Total Transformations Attempted : {total_count}")
    print(f"Total Successfully Verified     : {passed_count}")
    print(f"Safety Rollbacks                : {total_count - passed_count}")
    print(f"Verification Success Rate       : {(passed_count / total_count) * 100:.1f}%")
    print("=" * 86)

    return passed_count == total_count

def extracted_run(adapter, agent, plan_file):
    with open(plan_file, "r", encoding="utf-8") as pf:
        plan_data = json.load(pf)

    plans = plan_data.get("plans", [])
    results = []

    for idx, plan in enumerate(plans, 1):
        rel_target = plan["target"]
        full_path = os.path.join(SCRIPT_DIR, rel_target)
        with open(full_path, "r", encoding="utf-8") as f:
            source_code = f.read()

        step = plan["steps"][0]
        refactoring_name = step["refactoring"]

        req = adapter.build_request_from_rdp(
            request_id=f"demo_ecu_{idx}",
            language="c",
            source_code=source_code,
            planner_output=plan,
        )

        res = agent.execute(req)
        success = res.get("success", False)
        applied = res.get("transformation_applied", False)
        rollback = res.get("rollback_occurred", False)
        confidence = res.get("confidence_score", 0.0)
        status_label = res.get("status", "UNKNOWN")
        refactored = res.get("refactored_code", "")

        results.append({
            "file": rel_target,
            "refactoring": refactoring_name,
            "success": success,
            "applied": applied,
            "rollback": rollback,
            "confidence": confidence,
            "status": status_label,
        })

        if success and applied and not rollback:
            first_lines = [l for l in refactored.splitlines() if l.strip() and not l.startswith("#include")][:3]
            sample = " | ".join(l.strip() for l in first_lines)
            print(f"[{idx:02d}/{len(plans)}] PASS: {rel_target:<32} | {refactoring_name:<26} (Conf: {confidence:.3f}) | Sample: {sample[:35]}...")
        else:
            reason = res.get("safety_report", {}).get("rollback_reason", "Transformation validation check failed")
            print(f"[{idx:02d}/{len(plans)}] FAIL: {rel_target:<32} | {refactoring_name:<26} Reason: {reason}")
    return results

if __name__ == "__main__":
    success = run()
    sys.exit(0 if success else 1)
