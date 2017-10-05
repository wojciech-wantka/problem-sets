def main():
    input_file_name = 'rosalind_dna.txt'

    with open(input_file_name) as input_file:
        contents = input_file.read()

    occurrences = {
        'A': 0,
        'C': 0,
        'G': 0,
        'T': 0
    }

    for character in contents:
        occurrences[character] += 1

    print('{} {} {} {}'.format(occurrences['A'], occurrences['C'], occurrences['G'], occurrences['T']))

if __name__ == '__main__':
    main()
