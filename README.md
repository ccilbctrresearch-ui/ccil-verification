# CCIL — Causal Control Integrity Layer

**Formal verification of safety kernels for Autonomous Emergency Braking (AEB)**

[![DOI](https://img.shields.io/badge/DOI-10.5281%2Fzenodo.22797038-blue)](https://doi.org/10.5281/zenodo.22797038)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Lean 4](https://img.shields.io/badge/Lean-4.35.0--rc2-purple)](https://lean-lang.org/)
[![CBMC](https://img.shields.io/badge/CBMC-5.95.1-green)](https://www.cprover.org/cbmc/)

---

## Overview

CCIL provides a **Dual-Theorem framework** for AEB safety, mechanized in Lean 4 and cross-validated with CBMC. It establishes two mathematical guarantees:

- **Necessity:** Without a latency-aware safety kernel, collision is inevitable — for any physical parameters.
- **Sufficiency:** With such a kernel, safety holds for all steps, mathematically.

The framework targets **ISO 26262 ASIL-D**, **DO-178C Level A**, and **IEC 62304 Class C**.

## Verification Status

| Layer | Artifact | Status |
|-------|----------|--------|
| Formal proof (Lean 4) | 56 theorems, zero `sorry` | ✅ Complete |
| Runtime verification (C) | 15 verifiers, 300,000 iterations | ✅ Zero failures |
| Machine verification (CBMC) | 2 harnesses | ✅ `VERIFICATION SUCCESSFUL` |

## Repository Structure
