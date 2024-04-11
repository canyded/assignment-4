import java.util.HashMap;
import java.util.Map;

public class DoorWall extends Wall {
    private Room r1;
    private Room r2;
    private boolean isOpen;

    public DoorWall() {
        isOpen = false;
    }

    public void setRooms(Room r1, Room r2) {
        this.r1 = r1;
        this.r2 = r2;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        DoorWall doorWall = (DoorWall) super.clone();
        // Clone rooms references
        doorWall.r1 = (Room) r1.clone();
        doorWall.r2 = (Room) r2.clone();
        return doorWall;
    }

    public static class Maze {
        private Map<Integer, Room> rooms = new HashMap<Integer, Room>();

        public void addRoom(Room r) {
            rooms.put(r.getRoomNo(), r);
        }

        public Room roomNo(int r) {
            return rooms.get(r);
        }
    }

    public enum Direction {
        NORTH,
        EAST,
        SOUTH,
        WEST
    }

}
