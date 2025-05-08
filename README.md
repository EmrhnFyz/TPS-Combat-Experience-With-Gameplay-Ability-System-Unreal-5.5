# TPSCombat

A modular third-person action RPG demo built with Unreal Engine 5.5, inspired by games like God of War. 
This project demonstrates advanced gameplay systems, modular architecture, and modern Unreal Engine practices.


https://github.com/user-attachments/assets/c5f3910d-8da6-4174-995b-6d43c0f8f60f


https://github.com/user-attachments/assets/cdd2ce04-93ce-4c5a-a7e1-18a13d97485e


https://github.com/user-attachments/assets/857d7bcc-e16c-4098-8357-38dd6e06ba7d

## Features

- **TPS Camera & Controls**: Over-the-shoulder camera with smooth movement, target tock and aiming.
- **Modular Combat System**: 
  - Light and heavy attacks, special abilities (with cooldowns), and a rage system.
  - Easily extendable to add new skills, weapons, or abilities.
- **Survival Mode**: 
  - Fight waves of enemies, culminating in a boss battle.
  - Dynamic enemy spawning and wave management.
- **Rage Mechanic**: 
  - Fill the rage bar through combat, then activate for enhanced attacks.
- **Shield & Riposte System**:
  - Spawn a shield (hold Shift while weapon equipped) and counterattack with perfect timing.
- **Blueprint & C++ Integration**: 
  - Designed for rapid iteration and extensibility.
  - Gameplay abilities, UI, and enemy logic are all modular and data-driven.
- **Clean, Professional Codebase**: 
  - Follows Unreal Engine best practices.
  - Well-organized and ready for extension.

## Keybindings

| Key / Mouse              | Action                                                                 |
|--------------------------|------------------------------------------------------------------------|
| `1`                      | Equip/Unequip weapon                                                   |
| `Left Click`             | Light attack                                                           |
| `Right Click`            | Heavy attack                                                           |
| `Ctrl + Left Click`      | Special light attack (with cooldown)                                   |
| `Ctrl + Right Click`     | Special heavy attack (with cooldown)                                   |
| `Middle Mouse Click`     | Target lock                                                            |
| `Mouse Movement`         | Change locked target (while target lock is active)                     |
| `Shift` (with weapon)    | Spawn shield                                                           |
| `Shield + Perfect Timing`| Riposte attack; follow up with Left/Right Click for counter combo      |
| `Space + Direction`      | Roll in any direction                                                  |
| `E`                      | Interact with healing/rage stones dropped by enemies                   |


## Why This Project?

This project was created to deepen my understanding of Unreal Engine 5.5 and to showcase my skills in gameplay programming, 
modular system design, and C++/Blueprint integration. 
The codebase is designed to be readable, extensible.

## Extending the Project

- **Add new abilities**: Implement a new ability class and register it in the modular ability system.
- **Create new enemies**: Add new enemy blueprints and data assets; the wave system will handle spawning.
- **Customize UI**: Modular UI components make it easy to add new HUD elements or feedback.

---

*Built with Unreal Engine 5.5. All code and assets are for demonstration and educational purposes.*
