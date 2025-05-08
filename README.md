
# 🕹️ Cub3D

Cub3D is a minimalist raycasting-based 3D game engine developed in C, inspired by the classic *Wolfenstein 3D*.  
Created as part of the École 42 curriculum, this project offers an immersive first-person experience within a maze-like environment, utilizing the MiniLibX graphics library.

![Cub3D Screenshot](./9615b7c6-2ec8-42db-b768-18f9891b34cd.png)

> 📸 *Note: Screenshot from the actual project provided by user.*

---

## 📚 Table of Contents

- [✨ Features](#-features)
- [⚙️ Installation](#-installation)
- [🚀 Usage](#-usage)
- [🎮 Controls](#-controls)
- [📝 Configuration](#-configuration)
- [📦 Dependencies](#-dependencies)
- [🧰 Troubleshooting](#-troubleshooting)
- [🪪 License](#-license)

---

## ✨ Features

- 🧠 Real-time 3D rendering using raycasting
- 🧱 First-person navigation in a 3D maze
- 🖼️ Textured walls and floors
- 🧍 Basic collision detection
- 🗺️ Customizable maps via config files

---

## ⚙️ Installation

1. **Clone the repository:**

```bash
git clone https://github.com/ciusca42/Cub3D.git
cd Cub3D
```

2. **Build the project:**

```bash
make
```

👉 For bonus features, run:

```bash
make bonus
```

---

## 🚀 Usage

Run the game with:

```bash
./cub3D map.cub
```

📁 Replace `map.cub` with your desired map configuration.

---

## 🎮 Controls

| Key           | Action               |
|---------------|----------------------|
| `W`           | Move forward         |
| `S`           | Move backward        |
| `A`           | Strafe left          |
| `D`           | Strafe right         |
| ⬅️ / ➡️        | Rotate view left/right |
| `ESC`         | Exit the game        |

*🎯 Bonus version may include additional controls!*

---

## 📝 Configuration

`.cub` files define the game's world:

- 🖼️ Texture paths
- 🧭 Player start position and orientation
- 🧱 2D map layout

📌 Check the `map.cub` sample provided for reference.

---

## 📦 Dependencies

- 🛠️ GCC-compatible C compiler
- 🖼️ [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
- 🧰 `make` build tool

⚠️ Ensure MiniLibX is installed and properly linked.

---

## 🧰 Troubleshooting

- ❌ **Window not opening**: MiniLibX might not be set up correctly.
- ⌨️ **Unresponsive controls**: Ensure game window is focused.
- 📂 **Missing textures**: Verify file paths in `.cub` file.

---

## 👨‍💻 Author

- 🧑‍💻 [ciusca42](https://github.com/ciusca42)

---

## 🪪 License

📄 Licensed under the MIT License. See [LICENSE](LICENSE) for details.

---

🏁 For more info, check out the [repository](https://github.com/ciusca42/Cub3D).
