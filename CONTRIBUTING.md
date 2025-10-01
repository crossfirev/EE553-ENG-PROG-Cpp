# Contributing Guidelines

Welcome! 🎓
This repository documents coursework for **EE 553: Engineering Programming, C++** as part of my M.Eng. in Robotics at Stevens Institute of Technology.
Although this repo is primarily for my own use, I maintain it with the same workflows used in professional projects.

---

## 📌 Workflow Overview

The development flow for homework assignments is:

1. **Issue Creation**
   - Each homework starts with a GitHub Issue using the [Homework Issue Template](.github/ISSUE_TEMPLATE/homework.md).
   - The Issue documents the assignment description, problems, files provided, deliverables, and progress checklist.

2. **Branching**
   - A new branch is created from the Issue (e.g., `hw02-solution`).
   - Work is committed incrementally to this branch.

3. **Pull Request (PR)**
   - A Draft Pull Request is opened immediately after branching.
   - The PR serves as the *progress log* for solving the Issue.
   - The PR description uses the [Pull Request Template](.github/pull_request_template.md).

4. **Progress**
   - As commits are pushed, the PR updates automatically.
   - The Issue checklist and PR checklist track completion of each problem.

5. **Merge & Close**
   - Once the assignment is complete and submitted to Canvas, the PR is marked **Ready for Review** and merged into `main`.
   - The Issue is auto-closed with `Closes #X` in the PR description.

---

## ⚙️ Setup Guide

This repo uses **pre-commit hooks** to enforce consistent formatting and checks before commits.

### 1. Install dependencies

Make sure you have Python (3.8+) and `pip` available. Then run:

```
pip install pre-commit
```

### 2. Install hooks locally

From the root of the repo:

```
pre-commit install
```

This sets up git hooks so that every commit automatically runs the checks defined in `.pre-commit-config.yaml`.

### 3. Run hooks manually (optional)

You can run the hooks against all files at any time with:

```
pre-commit run --all-files
```

---

## 📂 Repository Structure

```
homework/
  hw01/   # Homework 1 source files
  hw02/   # Homework 2 source files
  ...
.github/
  ISSUE_TEMPLATE/           # Templates for Issues
  PULL_REQUEST_TEMPLATE/    # Templates for Pull Requests
```

---

## ✅ Standards

- **Code style:** Enforced by `.clang-format`.
- **Commits:** Descriptive, imperative mood (e.g., "Add prime check function").
- **File naming:** Keep assignment files under their respective `hwXX/` directories.
- **Precision/requirements:** Follow assignment specs closely (e.g., `setprecision(8)` for Problem 2).

---

## 🚀 Notes

This repo is educational and not intended for direct reuse by other students.
Links to Canvas assignments are included in Issues for personal reference, but require Stevens login.
