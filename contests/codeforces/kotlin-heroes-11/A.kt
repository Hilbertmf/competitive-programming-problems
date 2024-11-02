import kotlin.math.max

fun main() {
    var t = readln().toInt()
    for (i in 0 until t) {
        var n = readln().toInt()
        var MAX = 0
        var nums = readln().split(" ").map { it.toInt()}.toIntArray()
        for (j in 0 until n - 1) {
            MAX = max(MAX, nums[j])
        }
        if (nums[n - 1] - MAX == 1) {
            println(MAX)
        } else {
            println("Ambiguous")
        }
    }
}