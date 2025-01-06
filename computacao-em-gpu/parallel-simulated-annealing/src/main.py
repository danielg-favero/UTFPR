from readers.csv import CSVFileReader

def __main__():
    csv_reader = CSVFileReader()

    subjects = csv_reader.read("src/datasets/uftpr-subjects-2022-02.csv")
    rooms = csv_reader.read("src/datasets/utfpr-rooms-2022-02.csv")

__main__()