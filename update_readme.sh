#!/bin/bash

# Run the git ls-files command and count the number of .cpp files
num_cpp_files=$(git ls-files "*.cpp" | wc -l)

# Create a new badge string with the updated count
badge_string="![CPP Files](https://img.shields.io/badge/Problems_solved-$num_cpp_files-green)"

# Use sed to replace the old badge string with the new one in README.md
sed -i "s|!\[CPP Files\].*|$badge_string|" README.md

echo "Updated README.md with the count of .cpp files."
