import os
import argparse

from common import CheckSolution

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--repo-path", default=os.getcwd())
    args = parser.parse_args()

    REPO_PATH = args.repo_path

    author_solution_path = os.path.join(REPO_PATH, 'solution')

    solution_path_by_task_name = dict()

    for task_name in os.listdir(author_solution_path):
        solution_path_by_task_name[task_name] = os.path.join(author_solution_path, task_name)

    tasks_path = os.path.join(REPO_PATH, 'tasks') 

    task_path_by_task_name = dict()

    for task_theme in os.listdir(tasks_path):
        task_theme_path = os.path.join(tasks_path, task_theme)

        if not os.path.isdir(task_theme_path):
            continue

        for task_name in os.listdir(task_theme_path):
            task_path = os.path.join(task_theme_path, task_name)
            if task_name in solution_path_by_task_name:
                task_path_by_task_name[task_name] = task_path

    check_solution = CheckSolution(task_path_by_task_name, solution_path_by_task_name, REPO_PATH)
    report = check_solution.build_and_check()

    print(report)

    exit(report.is_failed())