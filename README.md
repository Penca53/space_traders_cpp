# space_traders_cpp

The C++ SDK to interact with the [Space Traders](https://spacetraders.io/) API v2.

Read the Space Traders API documentation [here](https://spacetraders.stoplight.io/docs/spacetraders/8e768e6831f6c-getting-started)

## Install

1) - A) Clone the repository
    ```sh
    git clone --recurse-submodules https://github.com/Penca53/space_traders_cpp.git
    ```
   - B) OR add a submodule to your repository
    ```sh
    git submodule add https://github.com/Penca53/space_traders_cpp.git ./your/path
    git submodule update --init --recursive
    ```

2) Add the following lines to your CMakeList.txt
```cmake
add_subdirectory(./path_to_deps/space_traders_cpp)
target_link_libraries(your-project-target-name PUBLIC space_traders_cpp)
```
3) Configure and build using CMake. 
On MacOS it might throw an error about OPEN_SSL. In order to fix it
you have to add it to your PATH, or try running:
```sh
brew upgrade openssl
brew link --force openssl
```

## Usage

The main object you'll be using is the `Session`. It holds all of the API endpoints and data needed to make requests.
You can create an anonymous `Session` without providing an authentication token which will only allow requests that don't need authentication.
You can create an authenticated `Session` by providing a valid token which will allow full API access.

All the exposed SDK methods require a `Request` parameter named after the endpoint and return a `Result<Response, Error>`, which can either be `Ok`, or `Err`.
An example signature is `Result<GetShipResponse, RequestError> GetShip(GetShipRequest);`

## Example

```cpp
// Create an authenticated session
Session auth_session("your-token");
// Make a request
auto get_ship_res = auth_session.GetShip(GetShipRequest{});


// Create an unauthenticated session
Session no_auth_session;

// Make a request (will fail because not authenticated)
auto get_ship_res = no_auth_session.GetShip(GetShipRequest{});

// Make it authenticated
LoginRequest login_req;
login_req.token = "your-token";
no_auth_session.Login(login_req);

// Make a request (will pass because authenticated)
auto get_ship_res = no_auth_session.GetShip(GetShipRequest{});
```
