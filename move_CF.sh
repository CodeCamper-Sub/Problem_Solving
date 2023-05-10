#!/bin/bash

# 현재 폴더 안에 있는 .cpp 파일들을 확인
for cpp_file in *.cpp; do
    # .cpp 확장자 제거
    base_name=$(basename "$cpp_file" .cpp)

    # tmp 폴더 안에 있는 .prob 파일 중에서 base_name을 포함하는 파일을 찾는다.
    prob_file=$(ls tmp/.${base_name}*.prob)

    if [ -f "$prob_file" ]; then
        # .prob 파일을 json으로 이루어져 있다. 이를 파싱해서 group 필드를 확인한다.
        group=$(python3 -c "import json; print(json.load(open('$prob_file'))['group'])")

        # 'Codeforces - '를 제거하고, Round 뒤의 숫자를 제거하여 대회 이름을 찾는다.
        contest_name=$(python3 -c "import re; print(re.sub('Codeforces - | Round [0-9]*', '', '$group'))")
        
        # Round 뒤의 숫자가 대회 번호이다.
        contest_number=$(python3 -c "import re; print(re.search(' Round ([0-9]*)', '$group').group(1))")

        # 'codeforces' 폴더 아래에 대회 이름 폴더를 생성하거나 찾고, 그 안에 대회 번호 폴더를 생성하거나 찾는다.
        mkdir -p "codeforce/$contest_name/$contest_number"
        
        # .cpp 파일을 해당 폴더로 이동한다.
        mv "$cpp_file" "codeforce/$contest_name/$contest_number"
    fi
done
