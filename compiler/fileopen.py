x = 1
while True:
    file_name = input("Enter file name: ")
    if file_name == "END":
        break
    
    with open("str/"+file_name+".txt", "w", encoding="UTF8") as file:
        while True:
            line = input(str(x) + ": ")
            if line == "END":
                break
            file.write(line + "\n")
            x += 1