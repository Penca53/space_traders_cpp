# space_traders_cpp

The C++ SDK to interact with the Space Traders API v2.

Read the Space Traders API documentation [here](https://spacetraders.stoplight.io/docs/spacetraders/8e768e6831f6c-getting-started)

## Install

1)
  - A) Clone the repository
  ```sh
  git clone --recurse-submodules https://github.com/Penca53/space_traders_cpp.git
  ```
  - B) Or add a submodule to your repository
  ```sh
  git submodule add https://github.com/Penca53/space_traders_cpp.git ./your/path
  git submodule update --init --recursive
  ```

2) Add the following lines to your CMakeList.txt
   ```cmake
   a
   ```
3) Configure and build using CMake

## Usage

The main object you'll be using is the `Session`. It holds all of the API endpoints and data needed to make requests.
You can create an anonymous `Session` without providing an authentication token which will only allow requests that don't need authentication.
You can create an authenticated `Session` by providing a valid token which will allow the full API access.

