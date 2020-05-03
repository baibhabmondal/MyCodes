package exercise

import scala.annotation.tailrec

object tailRec extends App{


  def concat(s: String, n: Int): String = {
    @tailrec
    def helper(a: String, acc: String, n: Int): String = {
      if(n == 0) acc
      else
        helper(a, acc + a, n-1)
    }

    if(n == 1) s else helper(s, "", n)
  }

  def fib(n: Int):Int = {
    @tailrec
    def helper(n: Int, acc: Int, i: Int): Int = {
      if(n == 1) acc
      else
        helper(n-1, acc + i, acc)
    }
    helper(n, 1, 1)
  }
  println(fib(5))

  println(concat("Alright! ", 3))
}
