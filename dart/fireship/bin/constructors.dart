void main() {
  var rect = Rectangle(25, 30);
  print('area: ${rect.area}');
  const cir = Circle(radius: 50, name: 'foo');

  var p1 = Point.fromMap({'lat': 23, 'lng': 50});
  var p2 = Point.fromList([23, 50]);
}

class Circle {
  const Circle({required int radius, String? name});
}

class Rectangle {
  final int width;
  final int height;
  late final int area;
  String? name;

  Rectangle(this.width, this.height, [this.name]) {
    area = width * height;
  }
}

class Point {
  double lat = 0;
  double long = 0;

  Point.fromMap(Map data) {
    lat = data['lat'];
    long = data['long'];
  }

  Point.fromList(List data) {
    lat = data[0];
    long = data[1];
  }
}
