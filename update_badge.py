import sys
import requests

def update_badge(count):
    badge_url = "https://img.shields.io/badge/cpp_files-{}-blue".format(count)
    readme_path = "README.md"  # Update if your README has a different name

    with open(readme_path, 'r') as file:
        readme = file.read()

    new_readme = readme.replace(
        r"![CPP Files](https://img.shields.io/badge/cpp_files-.*-blue)",
        "![CPP Files]({})".format(badge_url),
    )

    with open(readme_path, 'w') as file:
        file.write(new_readme)

if __name__ == "__main__":
    count = sys.argv[1]
    update_badge(count)
