import matplotlib.pyplot as plt

# Read data from file
file_path = 'vd.txt'
data_points = []

with open(file_path, 'r') as file:
    for line in file:
        point = line.strip().split(',')
        data_points.append((int(point[0]), float(point[1])))

# Separate the data points into two lists
x_values = [point[0] for point in data_points]
y_values = [point[1] for point in data_points]

# Plot the data points
plt.figure(figsize=(10, 6))
plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')
plt.xlabel('X Values')
plt.ylabel('Y Values')
plt.title('Plot of Data Points')
plt.grid(True)
plt.show()
