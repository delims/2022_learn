//
//  FacadePattern.cpp
//  DesignPattern
//
//  Created by delims on 2022/4/7.
//

#include <stdio.h>

/**
 外观模式（Facade Pattern）隐藏系统的复杂性，并向客户端提供了一个客户端可以访问系统的接口。这种类型的设计模式属于结构型模式，它向现有的系统添加一个接口，来隐藏系统的复杂性。

 意图：为子系统中的一组接口提供一个一致的界面，外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。

 主要解决：降低访问复杂系统的内部子系统时的复杂度，简化客户端之间的接口。

 何时使用： 1、客户端不需要知道系统内部的复杂联系，整个系统只需提供一个"接待员"即可。 2、定义系统的入口。

 优点： 1、减少系统相互依赖。 2、提高灵活性。 3、提高了安全性。

 缺点：不符合开闭原则，如果要改东西很麻烦，继承重写都不合适。
 
 使用场景： 1、为复杂的模块或子系统提供外界访问的模块。 2、子系统相对独立。 3、预防低水平人员带来的风险。

 */

// 一个对象里包含很多不同的对象，ShapeMaker 对象提供一致的接口调用内部对象的方法

//public class ShapeMaker {
//   private Shape circle;
//   private Shape rectangle;
//   private Shape square;
//
//   public ShapeMaker() {
//      circle = new Circle();
//      rectangle = new Rectangle();
//      square = new Square();
//   }
//
//   public void drawCircle(){
//      circle.draw();
//   }
//   public void drawRectangle(){
//      rectangle.draw();
//   }
//   public void drawSquare(){
//      square.draw();
//   }
//}
