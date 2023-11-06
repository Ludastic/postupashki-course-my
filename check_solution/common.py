import os
import subprocess

class CheckReport:
    def __init__(self):
        self.builds_failed = []
        self.tests_failed = []

    def is_failed(self):
        return not (len(self.builds_failed) == 0 and len(self.tests_failed) == 0)

    def __str__(self):
        if not self.is_failed():
            return 'all tests have been passed'

        res =  '\n  '.join(['failed tests:', *self.tests_failed])
        res += '\n'
        res += '\n  '.join(['failed builds:', *self.builds_failed])

        return res


class CheckSolution:
    def __init__(self, task_path_by_task_name, solution_path_by_task_name, repo_path):
        self.task_path_by_task_name = task_path_by_task_name
        self.solution_path_by_task_name = solution_path_by_task_name

        self.repo_path = repo_path
        self.build_path = os.path.join(repo_path, 'build')

        self.report = CheckReport()
        
    def build(self):
        os.makedirs(self.build_path, exist_ok=True)
        return subprocess.run(["cmake", ".."], cwd=self.build_path).returncode == 0

    def build_and_check(self):
        if not self.build():
            raise RuntimeError("bad build tree")
        
        for (task_name, task_path) in self.task_path_by_task_name.items():
            task_checker = TaskChecker(task_name, task_path, self.repo_path)
            task_checker.set_files(self.solution_path_by_task_name[task_name])

            if not task_checker.build_task():
                self.report.builds_failed.append(task_name)
                continue
            
            if not task_checker.run_tests():
                self.report.tests_failed.append(task_name)

        return self.report


class TaskChecker:
    def __init__(self, task_name, task_path, repo_path):
        self.task_path = task_path
        self.task_name = task_name
        self.repo_path = repo_path
        self.build_path = os.path.join(repo_path, 'build')

    def set_files(self, files_path):
        for file in os.listdir(files_path):
            subprocess.run(["mv", os.path.join(files_path, file), self.task_path])

    def build_task(self):
        return subprocess.run(["make", f"test_{self.task_name}"], cwd=self.build_path).returncode == 0
    
    def run_tests(self):
        return subprocess.run(f"./test_{self.task_name}", cwd=self.build_path).returncode == 0