class MedianFinder:
    def __init__(self):
        self.arr = []
    def addNum(self, num: int) -> None:
        from bisect import insort
        insort(self.arr, num)
    def findMedian(self) -> float:
        if len(self.arr) % 2 == 0:
            return (self.arr[len(self.arr)//2]+self.arr[(len(self.arr)//2)-1])/2
        else:
            return self.arr[len(self.arr)//2]