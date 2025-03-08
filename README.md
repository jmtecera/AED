<div align="center">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="./images/cimec_light.png">
    <img src="./images/cimec_dark.png">
  </picture>

<h1>Data Structures and Algorithms</h1>

</div>

[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)

The AED repository is a collection of programming exercises and solutions, serving as a practical record of concepts learned in data structures and algorithms. This repository is designed to support individual academic projects at FICH - UNL and incorporates evaluating code from CIMEC - UNL.
## Run Locally

Clone the project

```bash
  git clone https://github.com/jmtecera/AED.git
```

Navigate to the Project Directory

```bash
  cd AED
```

### For GTP-type files directories

| Action                | Command         | Description                               |
| :---------------------|:----------------|:------------------------------------------|
| Build [**required**]  | `make build`    | Compiles all exercises.                   |
| Run [**required**]    | `make run-[ex]` | Runs specific exercise.                   |
| Clean [*optional*]    | `make clean`    | Deletes all build files in the directory. |


### For TPL-type files directories

| Action                | Command      | Description                                             |
| :---------------------|:-------------|:--------------------------------------------------------|
| Build [**required**]  | `make build` | Compiles and automatically runs the exercise.           |
| Run   [*optional*]    | `make run`   | Runs the current exercise.                              |
| Clean [*optional*]    | `make clean` | Deletes all build files in the directory.               |


## Tests

Each TPL-type directory includes test cases in a specific JSON file, which are evaluated automatically whenever the target file is run.
## Roadmap

- Add missing TPL files and exercises.
- Fix any Makefiles that do not work correctly when building multiple exercises.


## Feedback

If you have any feedback or suggestions, feel free to reach out to me through the email on my GitHub profile.


## License
For more information, please refer to the [LICENSE](https://github.com/jmtecera/AED/blob/main/LICENSE) file.
