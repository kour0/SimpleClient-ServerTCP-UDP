# Chat TCP Simple (Serveur & Client)

## Description

Ce projet comprend deux applications séparées : un **serveur** et un **client**, qui permettent une communication de chat simple via TCP.

## Prérequis

- Compilateur C (GCC recommandé)

## Compilation

### Serveur TCP

Pour compiler le serveur, exécutez la commande suivante dans le terminal :

```bash
gcc serveurTCP.c -o serveurTCP
```

### **Client TCP**

Pour compiler le client, exécutez cette commande :

```bash
gcc clientTCP.c -o clientTCP
```

## **Exécution**

### **Serveur TCP**

Pour démarrer le serveur, utilisez :

```bash
./serveurTCP
```

Le serveur écoutera les connexions entrantes sur le port 8080. Assurez-vous que ce port est libre ou ajustez le code source pour utiliser un port différent.

### **Client TCP**

Pour exécuter le client :

```bash
./clientTCP <address-server> <port-server>
```

Assurez-vous que le serveur est déjà en cours d'exécution et écoute sur le port spécifié.

## **Utilisation**

Le client tente de se connecter au serveur dès son lancement. Une fois connecté, il peut envoyer des messages en les tapant dans le terminal. Le serveur répondra avec des messages simples.

Les messages apparaissent au fur et à mesure qu’ils sont reçus

# Day UDP Simple (Serveur & Client)

## Description

Ce projet comprend deux applications séparées : un **serveur** et un **client**, qui permettent une communication où le client envoie l’heure via UDP au serveur.

## Prérequis

- Compilateur C (GCC recommandé)

## Compilation

### Serveur UDP

Pour compiler le serveur, exécutez la commande suivante dans le terminal :

```bash
gcc serveurUDP.c -o serveurUDP
```

### **Client UDP**

Pour compiler le client, exécutez cette commande :

```bash
gcc clientUDP.c -o clientUDP
```

## **Exécution**

### **Serveur UDP**

Pour démarrer le serveur, utilisez :

```bash
./serveurUDP
```

Le serveur écoutera les connexions entrantes sur le port 8080. Assurez-vous que ce port est libre ou ajustez le code source pour utiliser un port différent.

### **Client UDP**

Pour exécuter le client :

```bash
./clientUDP <address-server> <port-server>
```

Assurez-vous que le serveur est déjà en cours d'exécution et écoute sur le port spécifié.

## **Utilisation**

Le client envoie l'heure locale actuelle au serveur, et le serveur reçoit ce message et l'affiche dans la console.
