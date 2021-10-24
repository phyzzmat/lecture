from os import system

test = 0
while True:
    test += 1
    print("Running on test", test)
    system("./generator.py > input.txt")
    system("./correct < input.txt > output_corr.txt")
    system("./wrong < input.txt > output_wrong.txt")
    output_corr = open("output_corr.txt").read().strip()
    output_wrong = open("output_wrong.txt").read().strip()
    if output_corr != output_wrong:
        print("Mismatch on test", test)
        print("Correct solution output:", output_corr)
        print("Wrong solution output:", output_wrong)
        break