Repo pour le TIPE de 2024-2026 sur les réseaux de neurones récurrents dans les JRPGs. 

## Structure
- `mGBA-interface` : Librairie en C pour communiquer avec mGBA : appuyer sur des touches, lire la map. Pour plus d'informations, voir le [README](mGBA-interface/README.md).
- `mGBASocketServer.lua` : Script Lua utilisant l'API de mGBA pour faire le pont avec ``mGBA-interface`` à travers un socket.