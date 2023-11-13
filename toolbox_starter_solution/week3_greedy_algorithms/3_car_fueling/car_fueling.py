from sys import stdin


def min_refills(distance, tank, stops):
    stops.insert(0, 0)  # Insert the starting point at the beginning of the stops list.
    stops.append(distance)  # Add the destination as the final stop.
    
    num_refills = 0  # Initialize the number of refills to 0.
    current_refill = 0  # Initialize the index of the current gas station.
    
    while current_refill < len(stops) - 1:
        last_refill = current_refill
        
        # Find the farthest gas station the car can reach from the current one.
        while current_refill < len(stops) - 1 and stops[current_refill + 1] - stops[last_refill] <= tank:
            current_refill += 1
        
        if current_refill == last_refill:
            return -1  # Unable to reach the next gas station.
        
        if current_refill < len(stops) - 1:
            num_refills += 1
    
    return num_refills

if __name__ == '__main__':
    d, m, _, *stops = map(int, stdin.read().split())
    # d, m, stops = 950, 400, [200, 375, 550, 750]
    print(min_refills(d, m, stops))
