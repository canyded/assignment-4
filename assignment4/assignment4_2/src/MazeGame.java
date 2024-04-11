public class MazeGame {
    public static void main(String[] argv) {
        createMaze();
    }

    private static DoorWall.Maze createMaze() {
        Room prototypeRoom = new Room(0);
        Wall prototypeWall = new Wall();
        DoorWall prototypeDoorWall = new DoorWall();

        MazePrototypeFactory factory = new MazePrototypeFactory(prototypeRoom, prototypeWall, prototypeDoorWall);

        DoorWall.Maze aMaze = new DoorWall.Maze();
        Room r1 = factory.makeRoom(1);
        Room r2 = factory.makeRoom(2);
        DoorWall d = factory.makeDoorWall(r1, r2);

        aMaze.addRoom(r1);
        aMaze.addRoom(r2);

        r1.setSide(DoorWall.Direction.NORTH, d);
        r1.setSide(DoorWall.Direction.EAST, factory.makeWall());
        r1.setSide(DoorWall.Direction.SOUTH, factory.makeWall());
        r1.setSide(DoorWall.Direction.WEST, factory.makeWall());
        r2.setSide(DoorWall.Direction.NORTH, factory.makeWall());
        r2.setSide(DoorWall.Direction.EAST, factory.makeWall());
        r2.setSide(DoorWall.Direction.SOUTH, d);
        r2.setSide(DoorWall.Direction.WEST, factory.makeWall());

        return aMaze;
    }
}
