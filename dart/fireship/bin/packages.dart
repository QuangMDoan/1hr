//import 'constructors.dart' as my_shapes;
import 'constructors.dart' hide Circle;
import 'constructors.dart' show Rectangle;

class Circle {}

void main() {
  Circle();
  Rectangle(1, 2);
}
