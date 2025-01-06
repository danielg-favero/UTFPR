from abc import ABC, abstractmethod

class FileReader(ABC):
    def __init__(self, mode = 'r', encoding = 'utf-8'):
        self.mode = mode
        self.encoding = encoding

    @abstractmethod
    def read(self, path: str):
        pass