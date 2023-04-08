import os
import random
import subprocess
from pathlib import Path
import time
import platform

# constants
input_file_path = Path("/Users/hangyeongsu/git/Eric-HanGyeongSoo/Problem_Solving/atCoder/Regular/159/input.txt")
solution_a_path = Path("/Users/hangyeongsu/git/Eric-HanGyeongSoo/Problem_Solving/atCoder/Regular/159/B.cpp")
solution_b_path = Path("/Users/hangyeongsu/git/Eric-HanGyeongSoo/Problem_Solving/atCoder/Regular/159/_B.cpp")

solution_a_path = str(solution_a_path)
solution_b_path = str(solution_b_path)

def filename_after_compile(string):
    last_period_index = string.rfind('.')
    
    if last_period_index == -1:
        return string
    
    result = string[:last_period_index]
    if platform.system() == "Windows":
        result += ".exe"
    return result

def compile():
    command = f"g++ -std=c++17 {solution_a_path} -o {filename_after_compile(solution_a_path)}"
    print(command)
    result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, text=True)
    if result.returncode != 0:
        print("Error in compiling first solution")
        return False
    command = f"g++ -std=c++17 {solution_b_path} -o {filename_after_compile(solution_b_path)}"
    result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, text=True)
    if result.returncode != 0:
        print("Error in compiling second solution")
        return False
    return True    


def generate_data():
    A = random.randint(1, 1000)
    B = random.randint(1, 1000)

    # Delete existing file
    if Path(input_file_path).is_file():
        os.remove(input_file_path)

    # Write data to file
    with open(input_file_path, "w") as inputFile:
        inputFile.write(f"{A} {B}\n")


def validate():
    file_command = "cat" if platform.system() != "Windows" else "type"

    # Execute first solution and save output
    command = f"{file_command} {input_file_path} | {filename_after_compile(solution_a_path)}"
    result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, text=True)
    if result.returncode != 0:
        print("Error in first solution")
        return False

    output1 = result.stdout.strip()

    # Execute second solution and save output
    command = f"{file_command} {input_file_path} | {filename_after_compile(solution_b_path)}"
    result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, text=True)
    if result.returncode != 0:
        print("Error in second solution")
        return False

    output2 = result.stdout.strip()

    # Compare outputs
    if output1 == output2:
        print("The outputs are the same.")
        return True
    else:
        print("The outputs are different.")
        return False


def main():
    random.seed(time.time())
    if not compile():
        return
    while True:
        generate_data()
        if not validate():
            break


if __name__ == "__main__":
    main()