import java.util.*

val dr = listOf(1, -1, 0, 0)
val dc = listOf(0, 0, 1, -1)

fun valid(r: Int, c: Int, rows: Int, cols: Int): Boolean {
    return r in 0 until rows && c in 0 until cols
}

fun main() {
    val scanner = Scanner(System.`in`)
    val t = scanner.nextInt()
    repeat(t) {
        val n = scanner.nextInt()
        val h = scanner.nextInt()
        val b = scanner.nextInt()
        val grid = Array(2) { scanner.next() }
        var sheep = Pair(0, 0)
        val wolves = mutableListOf<Pair<Int, Int>>()
        for (i in 0 until 2) {
            for (j in 0 until n) {
                when (grid[i][j]) {
                    'S' -> sheep = Pair(i, j)
                    'W' -> wolves.add(Pair(i, j))
                }
            }
        }

        var cost: Long = 0
        var remainingWolves = wolves.size
        for (i in 0 until 4) {
            val nr = sheep.first + dr[i]
            val nc = sheep.second + dc[i]
            if (!valid(nr, nc, 2, n) || grid[nr][nc] != 'W') continue
            cost += h
            grid[nr] = grid[nr].substring(0, nc) + '.' + grid[nr].substring(nc + 1)
            remainingWolves--
        }

        if (remainingWolves == 0) {
            println(cost)
            return@repeat
        }

        var wolvesRight = 0
        var wolvesLeft = 0
        for (c in 0 until sheep.second) {
            if (grid[0][c] == 'W') wolvesLeft++
            if (grid[1][c] == 'W') wolvesLeft++
        }
        for (c in sheep.second until n) {
            if (grid[0][c] == 'W') wolvesRight++
            if (grid[1][c] == 'W') wolvesRight++
        }

        var best = Long.MAX_VALUE
        if (b.toLong() * 3L < best) best = b.toLong() * 3L
        if (h.toLong() * remainingWolves < best) best = h.toLong() * remainingWolves
        if (sheep.second == 0 || sheep.second == n - 1) {
            if (b.toLong() * 2L < best) best = b.toLong() * 2L
            if (remainingWolves * h.toLong() < best) best = remainingWolves * h.toLong()
            cost += best
        } else {
            if (wolvesLeft == 0 || wolvesRight == 0) {
                if (b.toLong() * 2L < best) best = b.toLong() * 2L
            } else {
                if (b.toLong() * 3L < best) best = b.toLong() * 3L
                if ((wolvesLeft * h.toLong()) + b.toLong() * 2L < best) best = (wolvesLeft * h.toLong()) + b.toLong() * 2L
                if (b.toLong() * 2L + (wolvesRight * h.toLong()) < best) best = b.toLong() * 2L + (wolvesRight * h.toLong())
            }
            cost += best
        }

        println(cost)
    }
}
