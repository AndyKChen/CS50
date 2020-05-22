def main():
    text = input("Text: ")
    w = words(text)
    l = letters(text) * (100 / w)
    s = sentences(text) * (100 / w)
    index = int(0.0588 * l - 0.296 * s - 15.8 + 0.5)

    if index < 1:
        print("Before Grade 1")

    elif index > 16:
        print("Grade 16+")

    else:
        print(f"Grade {index}")


def letters(text):
    letters = 0
    for i in range(len(text)):
        if text[i].isalpha():
            letters += 1
    return letters


def words(text):
    words = 1
    for i in range(len(text)):
        if text[i] == " ":
            words += 1
    return words


def sentences(text):
    sentences = 0
    for i in range(len(text)):
        if text[i] == "." or text[i] == "!" or text[i] == "?":
            sentences += 1
    return sentences


main()
