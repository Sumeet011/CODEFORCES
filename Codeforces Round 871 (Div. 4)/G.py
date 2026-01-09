import sys
import bisect

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    iterator = iter(input_data)
    try:
        t = int(next(iterator))
    except StopIteration:
        return

    starts = [1]
    curr = 1
    # Precompute enough levels for constraints implied by input range
    for i in range(1, 5000):
        curr += i
        starts.append(curr)

    results = []

    for _ in range(t):
        n = int(next(iterator))
        
        row = bisect.bisect_right(starts, n) - 1
        start_val = starts[row]
        c = n - start_val
        
        ans = 0
        
        # Calculate sum of squares using range logic directly
        # Instead of BFS, we calculate the exact range [min_idx, max_idx] at each level
        # Range at level 'row - k' is [max(0, c - k), min(row - k, c)]
        
        current_r = row
        current_start = starts[current_r]
        
        # Determine the number of levels to go up
        # We go from current_r down to 0
        
        dist = 0
        while current_r >= 0:
            # Valid indices in this row are 0 to current_r
            # Reachable indices form a range [c - dist, c]
            
            # Intersection of [0, current_r] and [c - dist, c]
            
            idx_min = c - dist
            if idx_min < 0: idx_min = 0
            
            idx_max = c
            if idx_max > current_r: idx_max = current_r
            
            if idx_min <= idx_max:
                val_start = starts[current_r] + idx_min
                val_end = starts[current_r] + idx_max
                
                # Sum of squares from val_start to val_end
                # Formula: n(n+1)(2n+1)/6
                
                s_end = val_end * (val_end + 1) * (2 * val_end + 1) // 6
                v_prev = val_start - 1
                s_start = v_prev * (v_prev + 1) * (2 * v_prev + 1) // 6
                
                ans += (s_end - s_start)
            
            current_r -= 1
            dist += 1
            
        results.append(str(ans))

    sys.stdout.write('\n'.join(results) + '\n')

if __name__ == '__main__':
    solve()