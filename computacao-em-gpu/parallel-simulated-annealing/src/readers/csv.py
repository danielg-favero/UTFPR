from .reader import FileReader
import csv

class CSVFileReader(FileReader):
    def __init__(self, delimiter=",", mode = 'r', encoding="utf-8"):
        super().__init__(mode, encoding)
        self.delimiter = delimiter

    def read(self, path: str):
        """
        Lê um arquivo CSV e retorna os dados como uma lista de dicionários.
        Cada dicionário representa uma linha, com as chaves sendo os nomes das colunas.
        """
        data = []

        try:
            with open(path, mode=self.mode, encoding=self.encoding) as file:
                reader = csv.DictReader(file, delimiter=self.delimiter)
                for row in reader:
                    data.append(row)
        except FileNotFoundError:
            print(f"Erro: O arquivo '{path}' não foi encontrado.")
        except Exception as e:
            print(f"Erro ao ler o arquivo: {e}")

        return data