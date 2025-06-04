#!/bin/bash

# Check for root permissions
if [[ "$EUID" -ne 0 ]]; then
  echo "Please run as root (e.g., sudo ./clear_port.sh PORT)"
  exit 1
fi

# Check for port argument
if [ -z "$1" ]; then
  echo "Usage: $0 <port>"
  exit 1
fi

PORT=$1

echo "Clearing all connections using port $PORT..."

# Find and kill processes using the port
PIDS=$(lsof -i :$PORT -t)

if [ -z "$PIDS" ]; then
  echo "No active connections found on port $PORT."
  exit 0
fi

echo "Found PIDs: $PIDS"
for PID in $PIDS; do
  echo "Killing PID $PID..."
  kill -9 $PID
done

echo "All connections on port $PORT have been terminated."
