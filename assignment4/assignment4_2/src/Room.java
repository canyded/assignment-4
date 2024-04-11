import java.util.HashMap;
import java.util.Map;

public class Room implements Cloneable {
    private Map<DoorWall.Direction, Wall> sides = new HashMap<DoorWall.Direction, Wall>();
    private int roomNo;

    public Room(int roomNo) {
        this.roomNo = roomNo;
    }

    public Wall getSide(DoorWall.Direction direction) {
        return sides.get(direction);
    }

    public void setSide(DoorWall.Direction direction, Wall wall) {
        sides.put(direction, wall);
    }

    public int getRoomNo() {
        return roomNo;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        Room room = (Room) super.clone();
        // Deep copy of sides map
        room.sides = new HashMap<>(sides);
        return room;
    }
}

