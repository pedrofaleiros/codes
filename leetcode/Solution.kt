import java.util.EmptyStackException
import java.util.LinkedHashMap
import java.util.PriorityQueue
import java.util.Stack

class Solution {
    //20. Valid Parentheses
    fun isValid(s: String): Boolean {
        val myStack = Stack<Char>()
        for (c in s) {
            when (c) {
                '(' -> myStack.push(c)
                '{' -> myStack.push(c)
                '[' -> myStack.push(c)
                ')' -> {
                    try {
                        val pop = myStack.pop()

                        if (pop != '(') {
                            return false
                        }
                    } catch (e: EmptyStackException) {
                        return false
                    }
                }

                '}' -> {
                    try {
                        val pop = myStack.pop()

                        if (pop != '{') {
                            return false
                        }
                    } catch (e: EmptyStackException) {
                        return false
                    }
                }

                ']' -> {
                    try {
                        val pop = myStack.pop()

                        if (pop != '[') {
                            return false
                        }
                    } catch (e: EmptyStackException) {
                        return false
                    }
                }
            }
        }
        return myStack.isEmpty()
    }

    //217. Contains Duplicate
    fun containsDuplicate(nums: IntArray): Boolean {
        val map = LinkedHashMap<Int, Int>()
        for (num in nums) {
            if (map[num] == null) {
                map[num] = num
            } else {
                false
            }
        }
        return true
    }

    //242. Valid Anagram
    fun isAnagram(s: String, t: String): Boolean {
        var sMap = LinkedHashMap<Char, Int>()
        var tMap = LinkedHashMap<Char, Int>()

        for (c in s) {
            if (sMap[c] == null) {
                sMap[c] = 1
            } else {
                sMap[c] = sMap[c]!! + 1
            }
        }

        for (c in t) {
            if (sMap[c] == null) {
                return false
            } else {
                sMap[c] = sMap[c]!! - 1
            }
        }

        for (c in s) {
            if (sMap[c] != 0) {
                return false
            }
        }

        return true
    }

    //238. Product of Array Except Self
    fun productExceptSelf(nums: IntArray): IntArray {
        //https://leetcode.com/problems/product-of-array-except-self/
        var product: IntArray = IntArray(nums.size) { 1 }

        var aux: Int = 1
        for (i in nums.indices) {
            product[i] = aux
            aux *= nums[i]
        }

        aux = 1
        for (i in nums.size - 1 downTo 0) {
            product[i] *= aux
            aux *= nums[i]
        }

        return product
    }

    //347. Top K Frequent Elements
    fun topKFrequent(nums: IntArray, k: Int): IntArray {
        //https://leetcode.com/problems/top-k-frequent-elements/
        val map = mutableMapOf<Int, Int>()
        for (num in nums) {
            map[num] = map.getOrDefault(num, 0) + 1
        }

        class Dupla(val valor: Int, val freq: Int)

        val queue = PriorityQueue<Dupla>(compareBy<Dupla> { it.freq }.reversed())

        for ((key, value) in map) {
            queue.add(Dupla(valor = key, freq = value))
        }

        val result = IntArray(k)
        for (i in 0..<k) {
            result[i] = queue.remove().valor
        }
        return result
    }

    //150. Evaluate Reverse Polish Notation
    fun evalRPN(tokens: Array<String>): Int {
        //https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
        fun calculate(token: String, stack: Stack<Int>) {
            val n1 = stack.pop()
            val n2 = stack.pop()
            when (token) {
                "+" -> stack.add(n2 + n1)
                "-" -> stack.add(n2 - n1)
                "*" -> stack.add(n2 * n1)
                "/" -> stack.add(n2 / n1)
            }
        }

        val stack = Stack<Int>()
        val result: Int = 0

        for (token in tokens) {
            when (token) {
                "+",
                "-",
                "*",
                "/" -> calculate(token, stack)

                else -> stack.add(token.toInt())
            }
        }

        return stack.pop()
    }

    //22. Generate Parentheses
    fun generateParenthesis(n: Int): List<String> {
        //https://leetcode.com/problems/generate-parentheses/description/
        fun backtrack(
            open: Int,
            close: Int,
            result: MutableList<String>,
            string: String
        ) {
            if (open > close || open < 0) return

            if (open == 0 && close == 0) {
                result.add(string)
            }

            backtrack(open - 1, close, result, "$string(")
            backtrack(open, close - 1, result, "$string)")
        }

        val result = mutableListOf<String>()

        backtrack(n, n, result, "")

        return result
    }

    //125. Valid Palindrome
    fun isPalindrome(s: String): Boolean {
        //https://leetcode.com/problems/valid-palindrome/description/
        var i = 0
        var j = s.length - 1
        while (i < j) {
            if (!s[i].isLetterOrDigit()) {
                i++
            } else if (!s[j].isLetterOrDigit()) {
                j--
            } else if (s[i].lowercase() != s[j].lowercase()) {
                return false
            } else {
                i++
                j--
            }
        }
        return true
    }
}
