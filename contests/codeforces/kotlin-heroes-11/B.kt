fun main() {
    var t = readln().toInt()
    for (i in 0 until t) {
        var n = readln().toInt()
        
        var nums = mutableListOf<Int>()
        nums.add(1)
        for (j in n downTo 2) {
            nums.add(j)
        }

        print(nums.joinToString(" "))
        println()
    }
}