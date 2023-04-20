#!/bin/bash

for file_path in *.cpp; do
    if [[ "$file_path" =~ ([0-9]+)\.cpp ]]; then
        file_name="${BASH_REMATCH[1]}"
        folder_name="baekjoon/$(($((file_name-1))/1000 * 1000 + 1))-$(($((file_name-1))/1000 * 1000 + 1000))"
        new_file_path="$folder_name/$file_path"
        mkdir -p "$folder_name"
        mv "$file_path" "$new_file_path"
    else
        echo "File $file_path does not match the expected format."
    fi
done
