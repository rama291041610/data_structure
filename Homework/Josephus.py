class Josephus():
    def __init__(self, n):
        self.n = n
        self.member = list([i for i in range(1, n + 1)])
        self.loser = []

    def kill(self, k):
        cnt = 0
        l = len(self.member)
        while l > 1:
            cnt += 1
            if cnt % k == 0:
                self.loser.append(self.member[0])
                self.member.pop(0)
            else:
                self.member.append(self.member[0])
                self.member.pop(0)
            l = len(self.member)
        self.winner = self.member[0]


if __name__ == '__main__':
    n = input("Please input the total number of people:\n")
    J = Josephus(int(n))
    k = input("Please input K:\n")
    J.kill(int(k))
    print("The winner is NO.", J.winner)
