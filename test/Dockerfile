# Step 1: Use an official image with build tools and GCC pre-installed
FROM gcc:latest

# Step 2: Set the working directory in the container
WORKDIR /usr/src/app

# Step 3: Copy the current directory's contents to the container's working directory
COPY . .

# Step 4: Compile the C++ program
RUN g++ -o box box.cpp

# Step 5: Command to run the compiled program
CMD ["./myapp"]
