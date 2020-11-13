
with open("token.txt", "r") as f:
    for i in range(7):
        f.readline()
    for line in f:
        words = line.split("->")
        token = words[0].strip()
        desc = words[1].strip()
        # print(token, desc)
        # "}" {fprintf(stdout, "RC\n");}
        print("\"" + desc + "\" { fprintf(stdout, \"" + token + "\\n\"); }")