import java.util.HashMap;
import java.util.Map;

public class MazePrototypeFactory {
    private final Room prototypeRoom;
    private final Wall prototypeWall;
    private final DoorWall prototypeDoorWall;

    public MazePrototypeFactory(Room prototypeRoom, Wall prototypeWall, DoorWall prototypeDoorWall) {
        this.prototypeRoom = prototypeRoom;
        this.prototypeWall = prototypeWall;
        this.prototypeDoorWall = prototypeDoorWall;
    }

    public Room makeRoom(int roomNo) {
        try {
            return (Room) prototypeRoom.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
            return null;
        }
    }

    public Wall makeWall() {
        try {
            return (Wall) prototypeWall.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
            return null;
        }
    }

    public DoorWall makeDoorWall(Room r1, Room r2) {
        try {
            DoorWall doorWall = (DoorWall) prototypeDoorWall.clone();
            doorWall.setRooms(r1, r2);
            return doorWall;
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
            return null;
        }
    }
}
