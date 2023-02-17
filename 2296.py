class TextEditor:

    def __init__(self):
        self.l = []
        self.r = []

    def addText(self, text: str) -> None:
        self.l.extend(text)

    def deleteText(self, k: int) -> int:
        for i in range(k):
            if self.l:
                self.l.pop()
            else:
                return i
        return k

    def cursorLeft(self, k: int) -> str:
        for i in range(k):
            if self.l:
                self.r.append(self.l.pop())
            else:
                break
        return ''.join(self.l[-10:])

    def cursorRight(self, k: int) -> str:
        for i in range(k):
            if self.r:
                self.l.append(self.r.pop())
            else:
                break
        return ''.join(self.l[-10:])