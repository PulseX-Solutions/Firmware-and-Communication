import dash
from dash import dcc, html
from dash.dependencies import Input, Output
import plotly.graph_objs as go
import numpy as np
from collections import deque
import time

# Initialize the Dash app
app = dash.Dash(__name__)

# Create a deque to hold the data
max_length = 50
x_data = deque(maxlen=max_length)
y_data = deque(maxlen=max_length)

# Initialize with some data
x_data.append(0)
y_data.append(0)

# Data generation functions
def generate_high_amplitude_high_frequency():
    return np.sin(2 * np.pi * np.random.uniform(0.1, 0.5) * np.linspace(0, 1, 1)) * np.random.uniform(5, 10)

def generate_low_amplitude_low_frequency():
    return np.sin(2 * np.pi * np.random.uniform(0.01, 0.1) * np.linspace(0, 1, 1)) * np.random.uniform(2, 5)

# Layout of the Dash app
app.layout = html.Div(
    [
        dcc.Graph(id="live-graph", animate=True),
        dcc.Interval(
            id="graph-update", interval=1000, n_intervals=0  # Interval in milliseconds
        ),
    ]
)

# Callback to update the graph
@app.callback(
    Output("live-graph", "figure"),
    Input("graph-update", "n_intervals"),
)
def update_graph_scatter(n):
    # Time to switch data types (e.g., 10 seconds of high amplitude/high frequency data)
    switch_time = 10
    current_time = n * 1  # Time in seconds since the last interval

    if current_time < switch_time:
        # Generate high amplitude/high frequency data
        new_y = generate_high_amplitude_high_frequency()
    else:
        # Generate low amplitude/low frequency data
        new_y = generate_low_amplitude_low_frequency()

    # Update x and y data
    x_data.append(x_data[-1] + 1 if x_data else 0)
    y_data.append(new_y)

    # Create the figure
    data = go.Scatter(
        x=list(x_data),
        y=list(y_data),
        mode="lines+markers",
    )

    return {"data": [data], "layout": go.Layout(xaxis=dict(range=[min(x_data), max(x_data)]),
                                                yaxis=dict(range=[-10, 10]))}

# Run the app
if __name__ == "__main__":
    app.run_server(host='0.0.0.0', port=8050, debug=True)