import os
import subprocess

def ensure_dir_exists(path):
    if not os.path.exists(path):
        os.makedirs(path)

def clone_or_pull(repo_url, target_dir):
    repo_name = os.path.basename(repo_url).replace('.git', '')
    repo_path = os.path.join(target_dir, repo_name)

    if os.path.isdir(repo_path):
        # If the repository already exists, pull the latest changes
        print(f"Pulling latest changes for {repo_name}")
        subprocess.run(['git', '-C', repo_path, 'pull'], check=True)
    else:
        # Otherwise, clone the repository
        print(f"Cloning repository {repo_name}")
        subprocess.run(['git', 'clone', repo_url, repo_path], check=True)

def main():

    # Ensure the 'dependencies' directory exists
    ensure_dir_exists("dependencies")

    # List of repository URLs to clone or pull
    repo_urls = [
        'git@github.com:thephonebelinging/Utility.git',
        'git@github.com:ThePhoneBeLinging/EngineBase.git',
        # Add more repository URLs as needed
    ]

    # Clone or pull each repository
    for repo_url in repo_urls:
        path = "dependencies"
        if (os.getcwd().endswith("Scripts")):
            path = "../dependencies"
        clone_or_pull(repo_url, path)
    ensure_dir_exists("Resources")
if __name__ == '__main__':
    main()