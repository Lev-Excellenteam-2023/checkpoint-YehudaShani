import subprocess

def open_cmd_terminal(command):
    subprocess.Popen(f'start cmd /K {command}', shell=True)

if __name__ == "__main__":
    num_terminals = 10

    # List of commands to run in each terminal
    commands = [
        "ping 192.168.40.128"
    ]

    for i in range(400):
        subprocess.Popen(commands[0], shell=True)