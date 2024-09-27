from collections import defaultdict

# Graph to represent the tree
tree = defaultdict(list)

# DFS to find the farthest node, distance, and path
def dfs(node, parent, distance):
    farthest_node = node
    max_distance = distance
    path = [node]

    for neighbor in tree[node]:
        if neighbor != parent:  # Avoid going back to the parent
            child_farthest, child_distance, child_path = dfs(neighbor, node, distance + 1)
            if child_distance > max_distance:
                max_distance = child_distance
                farthest_node = child_farthest
                path = [node] + child_path  # Update the path with the current node
            elif child_distance == max_distance:  # If distance is the same, consider both paths
                path = [path, [node] + child_path]  # Store both paths

    return farthest_node, max_distance, path

# Helper function to flatten paths if there are multiple paths of the same length
def flatten_paths(paths):
    if not isinstance(paths[0], list):  # If there's a single path, just return it
        return [paths]
    else:  # If there are multiple paths, recursively flatten them
        flattened = []
        for path in paths:
            if isinstance(path[0], list):
                flattened.extend(flatten_paths(path))
            else:
                flattened.append(path)
        return flattened

# Function to find the longest paths in the tree
def find_longest_paths(tree):
    # Step 1: Pick an arbitrary node, say node 0 (assuming the nodes are labeled from 0)
    start_node = 0
    
    # Step 2: Find the farthest node from the start_node
    node_A, _, _ = dfs(start_node, -1, 0)
    
    # Step 3: Find the farthest node from node_A and also record the paths
    node_B, longest_path_length, longest_paths = dfs(node_A, -1, 0)
    
    # Flatten the longest paths in case multiple paths exist with the same length
    all_longest_paths = flatten_paths(longest_paths)
    
    return longest_path_length, all_longest_paths

# Example usage:
# Add edges to the tree (undirected)
tree[0].extend([1, 2])
tree[1].extend([0, 3, 4])
tree[2].extend([0])
tree[3].extend([1])
tree[4].extend([1, 5])
tree[5].extend([4])

# Find the longest paths in the tree and print the paths
longest_path_length, all_longest_paths = find_longest_paths(tree)
print("Longest Path Length:", longest_path_length)
print("All Longest Paths:")
for path in all_longest_paths:
    print(path)
