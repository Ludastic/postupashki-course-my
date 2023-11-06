import argparse
import git
import os
import shutil
import yaml

DUMMY_REPO_DIR_NAME = '.dummy'
TASK_CONFIG_FILE = 'task_config.yaml'

if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument(
        "-t", "--task-path",
        dest="task_path",
        default=None
    )

    args = parser.parse_args()

    task_path = ''
    task_theme = ''
    task_name = ''
    if args.task_path is None:
        task_path = os.getcwd()
        task_theme = os.path.basename(os.path.dirname(task_path))
        task_name = os.path.basename(task_path)

    submission_branch_name = f'submission/{task_theme}/{task_name}'

    base_repo = git.Repo("../../../")
    student_url = base_repo.remote("student").url

    dummy_repo_path = os.path.join(task_path, DUMMY_REPO_DIR_NAME)

    if os.path.exists(dummy_repo_path):
        shutil.rmtree(dummy_repo_path)

    os.makedirs(dummy_repo_path)

    dummy_repo = git.Repo.init(dummy_repo_path)

    dummy_repo.create_remote("student", url=student_url)

    task_config_path = os.path.join(task_path, TASK_CONFIG_FILE)

    pipeline_conf_path = os.path.join(dummy_repo_path, '.gitlab-ci.yml')
    shutil.copy('../../../test_solution.yml', pipeline_conf_path)

    dummy_repo.git.checkout("-b", "gitlab-pipeline-config")
    dummy_repo.index.add(pipeline_conf_path)
    dummy_repo.index.commit(f"add data for gitlab")

    with open(task_config_path, 'r') as file:
        task_config = yaml.safe_load(file)

    for file in os.listdir(task_path):
        if file in task_config["enable_change"]:
            dummy_dst_file = os.path.join(task_path, DUMMY_REPO_DIR_NAME, file)
            task_src_file = os.path.join(task_path, file)
            shutil.copy(task_src_file, dummy_dst_file)
            dummy_repo.index.add([dummy_dst_file])

    dummy_repo.index.commit(f"submit {submission_branch_name} task")

    dummy_repo.git.checkout("-b", submission_branch_name)

    dummy_repo.remote("student").push(
        submission_branch_name,
        o=f'merge_request.create',
        force=True
    )

    print('submitted.')
