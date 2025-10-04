# Use an official Python runtime as a parent image
FROM python:3.12-slim

# Set the working directory in the container
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY index.html /app/site/index.html

# Make port 8000 available to the world outside this container
EXPOSE 8000

# Run a simple HTTP server to serve the static site
CMD ["python3", "-m", "http.server", "8000", "--directory", "site"]

LABEL maintainer="Aminadab <s345428@studenti.polito.it>"