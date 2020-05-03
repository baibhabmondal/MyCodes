package exercise

import java.util.NoSuchElementException

import scala.annotation.tailrec

abstract class MyList[+T] {
  /*
    head : first element
    tail: remainder
    isEmpty:
    add(int) => new List with this element added
    toString (override) => string representation of the list
  */

    def head: T
    def tail: MyList[T]
    def isEmpty: Boolean
    def add[A >: T](x: A): MyList[A]
    def printString: String
    override def toString: String = {
      "[" + printString + "]"
  }
}

object LinkedList extends App {


  object EmptyList extends MyList[Nothing] {
      def head: Nothing = ???
      def tail: Nothing = ???
      def isEmpty: Boolean = true
      def add[A](x:A):MyList[A] = new demo(x, this)
      def printString: String = ""
  }

  class demo[+T](h: T, t: MyList[T]) extends MyList[T] {
    override def head: T = h;
    override def tail: MyList[T] = t
    override def isEmpty: Boolean = false
    override def add[A >: T](x: A): MyList[A] = new demo(x, this)
    def printString: String = {
      if(t.isEmpty) "" + head
      else head + " " + tail.printString
    }
  }

  val l: MyList[Int] = new demo(1,EmptyList)
  println(l.add(2).add(3).toString)
  println(new demo[String]("This", EmptyList).add("is").add("a").add("LinkedList").toString)
}

