class Publisher:
    def __init__(self):
        self.subscribers = set()
    def register(self, who):
        self.subscribers.add(who)
    def unregister(self, who):
        self.subscribers.discard(who)
    def dispatch(self, msg):
        for subscriber in self.subscribers:
            subscriber.update(msg)
    # Plus other methods for detecting events, 
    # ultimately calling self.dispatch().

class Subscriber():
    def __init__(self, name):
        self.name = name
    def update(self, msg):
        print(f'{self.name} got message "{msg}"')

class Subscriber2(): 
    def __init__(self, name):
        self.name = name
    def receive(self, msg):
        print(f'{self.name} got message "{msg}"')

class Subscriber2Adapter():
    def __init__(self, subscriber) -> None:
        self.subscriber = subscriber 
    def update(self, msg):
        self.subscriber.receive(msg)

class Subscriber3():
    def __init__(self, name):
        self.name = name
    def log(self, level, message):
        print(f'{level}: {self.name} got message "{message}"')

class Subscriber3Adapter():
    def __init__(self, subscriber) -> None:
        self.subscriber = subscriber 
    def update(self, msg):
        self.subscriber.log("Info", msg)

pub = Publisher()

an = Subscriber('An')
quang = Subscriber2Adapter(Subscriber2('Quang'))
thanh = Subscriber3Adapter(Subscriber3('Thanh'))

pub.register(an)
pub.register(quang)
pub.register(thanh)
pub.dispatch("Time for Dinner")

pub.unregister(thanh)
pub.dispatch("Time for Lunch")

