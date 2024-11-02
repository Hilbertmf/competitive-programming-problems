import java.util.*
import java.math.*

fun split(s: String, delim: Char): List<String> {
    return s.split(delim).filter { it.isNotEmpty() }
}

fun main() {
    var t = readln().toInt()
    for (i in 0 until t) {
        var line = readln()
        val plusCount = line.count { it == '+' }
        var ans = BigInteger.ZERO
        val strs = split(line, '+')

        if (plusCount == 1) {
            ans += strs[0].toBigInteger() + strs[1].toBigInteger()
        } else {
            ans += strs[0].toBigInteger()
            for (i in 1 until strs.size - 1) {
                var sum = BigInteger.ZERO
                var best2 = Pair(BigInteger.ZERO, BigInteger.ZERO)
                val s = strs[i]
                for (j in 1 until s.length) {
                    val curFirst = s.substring(0, j).toBigInteger()
                    val curSecond = s.substring(j).toBigInteger()
                    if (sum < curFirst + curSecond) {
                        sum = curFirst + curSecond
                        best2 = Pair(curFirst, curSecond)
                    }
                }
                ans += sum
            }
            ans += strs.last().toBigInteger()
        }

        println(ans)

    }
}